package src

/*
 * @lc app=leetcode.cn id=27 lang=golang
 *
 * [27] 移除元素
 */
// two-pointers

// @lc code=start
func removeElement(nums []int, val int) int {
	j := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == val {
			continue
		}
		nums[j] = nums[i]
		j++
	}
	return j
}

// @lc code=end
