package main

import (
	"flag"
	"fmt"
	"strings"
	"os/exec"
	"io/ioutil"
	"net/http"
	"crypto/sha1"
	"crypto/hmac"
	"github.com/gin-gonic/gin"
)

func genSign(key string, data string) string {
	h_key := []byte(key)
	mac := hmac.New(sha1.New, h_key)
	mac.Write([]byte(data))
	return fmt.Sprintf("%x", mac.Sum(nil))
}

func main() {
	/* 获取命令行Secret参数 */
	var secret string 
	flag.StringVar(&secret, "p", "123456", "default secret is 123456")
	flag.Parse()

	fmt.Println("secert: %s", secret)

	gin.SetMode(gin.ReleaseMode)
	router := gin.Default()

	/* 仅用于测试请求是否正常访问 */
	router.GET("/", func(c *gin.Context) {
		c.String(http.StatusOK, "Service For GitHub Webhook!")
	})

	/* 接收webhook请求 */
	router.POST("/deploy", func(c *gin.Context) {
		/* 获取请求头信息 */
		x_Event		:= c.Request.Header.Get("X-GitHub-Event")
		x_Signature	:= c.Request.Header.Get("X-Hub-Signature")

		/* 获取sign */
		x_sign 	:= strings.Split(x_Signature, "=")[1]
		/* 获取Body */
		req_body, _ := ioutil.ReadAll(c.Request.Body)
		req_str		:= string(req_body)
		my_sign		:= genSign(secret, req_str) /* 生成本地Sign */
		if x_sign == my_sign {		/* sign验证成功 */
			if x_Event == "push" {
				/* 如有需要，可以从body中获取想要的参数，方法如下: */
				// cmt_ref := gjson.Get(req_str,"ref")
				/* 执行Shell脚本 */
				_, err := exec.Command("sh","/app/deploy.sh").Output()
				if err != nil {
					fmt.Println(err)
				}
				c.JSON(http.StatusOK, "Success")
			} else {
				c.JSON(http.StatusOK, "Just Support Push Event")
			}
		} else {
			c.JSON(http.StatusOK, "Sign Error")
		}
	})
	
	router.Run(":8000")
}