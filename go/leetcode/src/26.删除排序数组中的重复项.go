package src

/*
 * @lc app=leetcode.cn id=26 lang=golang
 *
 * [26] 删除排序数组中的重复项
 */
// two-pointers

// @lc code=start
func removeDuplicates(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	i := 0
	for j := 1; j < len(nums); j++ {
		if nums[j] == nums[i] {
			continue
		}
		i++
		nums[i] = nums[j]
	}
	return i + 1
}

// @lc code=end
