# -*- coding: utf-8 -*-

'''
一只慢悠悠的m.weibo.cn的爬虫，它能做：
功能：
    1. 爬取指定博文的所有评论
    2. 爬取当前评论的用户详细信息（不想要用户数据：need_user_info传False）
特点：
    1.直接在m.weibo.cn中登录，省去了解密用户名和密码的过程，省去prelogin获取serverdata的步骤，代码简洁易懂
说明：
    微博显示的评论数和用户能查看到的实际评论数是不一致的，例如评论为1w+，实际真实用户看到只能1k+，那么该爬虫也能爬取到1k+的评论内容
'''

import os
import sys
import time
import requests
import re
import csv
import random
import traceback

from datetime import datetime
from http.cookiejar import LWPCookieJar
import json

from collections import OrderedDict

'''
通过登录weibo.com，然后跳转到m.weibo.cn
'''
class Weibo(object):

    def __init__(self, username, password):
        '''
        初始化
        '''
        super(Weibo, self).__init__()        
        self.cookie_file    = 'Cookie'
        self.session        = requests.Session()
        self.username       = username
        self.password       = password
        self.headers        = {'User-Agent':'mozilla/5.0 (windowS NT 10.0; win64; x64) appLewEbkit/537.36 (KHTML, likE gecko) chrome/71.0.3578.98 safari/537.36'}
        self.session.cookies = LWPCookieJar(filename=self.cookie_file)

    def __random_sleep(self):
        '''
        随机睡眠，防止爬虫爬取过快，导致一段时间无法访问微博服务器
        '''
        time.sleep(random.randint(5, 10))

    def __gen_headers(self):
        '''
        生成headers
        '''
        headers = {
            'User-Agent' : 'mozilla/5.0 (windowS NT 10.0; win64; x64) appLewEbkit/537.36 (KHTML, likE gecko) chrome/71.0.3578.98 safari/537.36',
            'Accept': '*/*',
            'Accept-Encoding': 'gzip, deflate, br',
            'Accept-Language': 'zh-CN,zh;q=0.9',
            'Connection': 'keep-alive',
            'Origin': 'https://passport.weibo.cn',
            'Referer': 'https://passport.weibo.cn/signin/login?entry=mweibo&res=wel&wm=3349&r=https%3A%2F%2Fm.weibo.cn%2F',
        }
        return headers

    def __gen_postdata_for_login(self):
        '''
        生成登录所需的postdata
        '''
        postdata = {
            'username': self.username,
            'password': self.password,
            'savestate': '1',
            'r': 'https://m.weibo.cn/',
            'ec': '0',
            'pagerefer': 'https://m.weibo.cn/login?backURL=https%253A%252F%252Fm.weibo.cn%252F',
            'entry': 'mweibo',
            'mainpageflag': '1',
        }

        return postdata

    def login(self):
        '''
        登录微博
        '''
        postdata = self.__gen_postdata_for_login()
        headers = self.__gen_headers()
        login_url = 'https://passport.weibo.cn/sso/login'
        login_page = self.session.post(login_url, data=postdata, headers=headers)

        if login_page.status_code != 200:
            return
            
        login_json = eval(login_page.text)

        print('[INFO]: 登录用户主页为https://m.weibo.cn/u/%s'%login_json['data']['uid'])

        config_url = 'https://m.weibo.cn/api/config'
        config = self.session.get(config_url, headers=self.headers)
  
        if config.json()['data']['login']:
            print('[INFO]: 用户登陆成功')
        else:
            print('[ERROR]: 用户登录失败')

        self.session.cookies.save()

        return

    def __get_csv_file(self, csvFileName='data.csv'):
        '''
        获取存储爬取结果的文件路径
        '''
        try:
            fileDir = os.path.split(os.path.realpath(__file__))[0]
            filePath = fileDir + os.sep + 'res'
            if not os.path.isdir(filePath):
                os.mkdir(filePath)
            filePath += os.sep + csvFileName
            return filePath
        except Exception as e:
            print('Error: ', e)
            traceback.print_exc()

    def __write_csv(self, csvFileName, dataList):
        '''
        将爬取的信息写入csv文件
        '''
        try:
            data = [ c.values() for c in dataList]
            with open(self.__get_csv_file(csvFileName), 'a', encoding='utf-8-sig', newline='') as f:
                writer = csv.writer(f)
                writer.writerows(data)
        except Exception as e:
            print('Error: ', e)
            traceback.print_exc()

    def __get_cmt_info(self, cmtJson):
        '''
        获取一条评论数据
        '''
        cmt = OrderedDict([
            ('screen_name', ''), ('urank', ''), ('mbrank', ''), ('id', ''), ('statuses_count', ''), 
            ('follow_count', ''), ('followers_count', '')
            ])
        try:
            for key in cmt.keys():
                cmt[key] = cmtJson['user'][key]

            tmpTime = cmtJson['created_at'].replace('+0800', '')
            cmt['created_at'] = datetime.strptime(tmpTime, '%a %b %d %H:%M:%S %Y')

            data = cmtJson['text'].replace(',','，')
            p = re.compile(r'(<span.*>.*</span>)*(<a.*>.*</ a>)?')
            cmt['data'] = p.sub(r'', data)

            cmt['like_count'] = cmtJson['like_count']

            cmt['total_number'] = 0
            if cmtJson['total_number']:
                cmt['total_number'] = cmtJson['total_number']

        except Exception:
            print('[Error]: 无法解析这条评论', cmtJson)
        finally:
            return cmt

    def __gen_user_homepage_url(self, user_id):
        '''
        生成获取用户主页的URL
        '''
        url  = u'https://m.weibo.cn/api/container/getIndex?type=uid'
        url += '&value=' + str(user_id)
        url += '&containerid=100505' + str(user_id)

        return url
    
    def __gen_user_baseinfo_url(self, user_id):
        '''
        生成获取用户基本资料的URL
        '''
        url  = u'https://m.weibo.cn/api/container/getIndex?'
        url += u'containerid=230283' + str(user_id) + '_-_INFO'
        url += u'&title=%E5%9F%BA%E6%9C%AC%E8%B5%84%E6%96%99' # &title=基本资料
        url += u'&luicode=10000011'
        url += u'&lfid=230283' + str(user_id)

        return url

    def __get_json_from_url(self, url):
        '''
        获取请求返回的json数据
        '''
        try:
            cookie_dict = requests.utils.dict_from_cookiejar(self.session.cookies)

            response = requests.get(url, headers=self.headers, cookies=cookie_dict)

            if response.status_code != 200:
                print('Error: 请求微博服务器失败！将在1分钟后重试。')
                return None

            return response.json()
        except Exception as e:
            print('Error: ', e)
            return None

    def __deal_user_homepage(self, userJson):
        '''
        处理用户主页信息
        '''
        userInfo = OrderedDict([('screen_name',''), ('id', ''), ('urank',''), ('mbrank',''), ('statuses_count',''), ('follow_count',''), ('followers_count','')])

        if userJson['ok'] == 0:
            print(u'Error: 获取该用户主页信息时返回了0。https://m.weibo.cn/u/%s' % user_id)
            return userInfo
        try:
            item = userJson['data']['userInfo']
            for key in userInfo.keys():
                userInfo[key] = item[key]
        except Exception:
            print(u'[Error]: 无法解析id为%s用户的主页信息'%userInfo['id'])
        finally:
            return userInfo

    def __deal_user_baseinfo(self, userJson):
        '''
        处理用户基本资料
        '''
        userInfo = OrderedDict([
            ('简介',''), ('注册时间',''), ('阳光信用',''), ('性别',''),
            ('生日',''), ('所在地',''), ('家乡',''), ('公司',''), ('公司','')
            ])

        if userJson['ok'] == 0:
            print(u'[Error]: 获取该用户基本资料时返回了0。')
            return userInfo
        try:
            for card_item in userJson['data']['cards']:
                    card_group = card_item['card_group']
                    for tmp in card_group:
                        if tmp == None:
                            continue
                        if tmp['card_type'] != 41:
                            continue
                        if not 'item_name' in tmp:
                            continue
                        if tmp['item_name'] in userInfo.keys():
                            userInfo[tmp['item_name']] = tmp['item_content']
        except Exception:
            print(u'[Error]: 无法解析该用户的基本资料')
        finally:
            return userInfo

    def __get_user_info(self, userId):
        '''
        获取用户信息
        '''
        self.__random_sleep()
        try:
            url = self.__gen_user_homepage_url(userId)
            userJson = self.__get_json_from_url(url)
            userDict1 = self.__deal_user_homepage(userJson)

            url = self.__gen_user_baseinfo_url(userId)
            userJson = self.__get_json_from_url(url)
            userDict2 = self.__deal_user_baseinfo(userJson)

            userDict = OrderedDict(userDict1, **userDict2)

        except Exception:
            print('[ERROR]: 获取id为%s用户数据失败'%userId)
        finally:
            return userDict

    def start_for_cmt_info(self, blogId, csvFileName):
        '''
        获取一条博客的全部评论内容
        '''
        print('[INFO]: 正在抓取id为' + blogId + '的微博评论数据...')
        startUrl = 'https://m.weibo.cn/comments/hotflow?id=' + blogId + '&mid=' + blogId

        cookie_dict = requests.utils.dict_from_cookiejar(self.session.cookies)

        url = startUrl + '&max_id_type=0'      # 第一页博客评论的URL
        try:
            while True:
                response = requests.get(url, headers=self.headers, cookies=cookie_dict)
                if response.status_code != 200:
                    print('[ERROR]: 请求微博服务器失败！将在1分钟后重试。')
                    time.sleep(60)
                    break

                cmts = response.json()

                if cmts['ok'] == 0:
                    print('[INFO]: 已经爬取id为' + blogId + '微博的全部评论')
                    break
                
                cmtList = []
                for cmtJson in cmts['data']['data']:
                    cmtInfo = self.__get_cmt_info(cmtJson)
                    if cmtInfo != None:
                        cmtList.append(cmtInfo)

                # 写入结果数据到csv文件
                self.__write_csv(csvFileName, cmtList)
                # 获取下一条爬取的URL
                url = startUrl + '&max_id=' + str(cmts['data']['max_id']) + '&max_id_type=' + str(cmts['data']['max_id_type'])
                self.__random_sleep()
        except Exception as e:
            print('Error: ', e)
            traceback.print_exc()

    def start_for_user_info(self, userIdList, csvFileName):
        '''
        获取指定用户id的基本资料
        '''
        try:
            for userId in userIdList:
                userInfo = self.__get_user_info(str(userId))
                self.__write_csv(csvFileName, [userInfo])
        except Exception as e:
            print('Error: ', e)

if __name__ == '__main__':

    weiboSpider = Weibo('xxxxxx@xxx.xxx', 'password****')
    weiboSpider.login()

    # 爬取指定博客的评论
    blog_id = [
        '4433839998710387',
        '4433847762379329',
        '4433859015841655',
        '4433878204338385',
        '4433910135682787',
        '4433913956578534',
        '4433925357004710',
        '4434142446172936',
        '4434267989743114',
        '4434546319684677',
        '4434636531072815',
        '4434859672074909',
        '4435039603106846',
        '4435284865431674',
        '4435595717463296',
        '4435604605429354',
        '4436045116605599',
        '4436111864145580',
        '4436128029513558'
    ]

    for i in range(1,20):
        weiboSpider.start_for_cmt_info(blog_id[i], str(i) + '.csv')


    # 爬取指定用户id的基本信息
    userIdList = ['5377343578', '2267360510', '5662802716', '6491386710', '6120794556', '5462352881', '5691701715', '6015174010']
    weiboSpider.start_for_user_info(userIdList, 'userinfo.csv')