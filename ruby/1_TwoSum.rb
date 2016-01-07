# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  h = Hash.new
  nums.each.with_index do |x, i|
    h[x] ||= []
    h[x] << i
  end

  nums.each.with_index do |x, i|

    match_indexes = h[target - x]

    if match_indexes
      match_indexes.each do |m|
        return [i+1, m+1].sort! if i != m
      end
    end
  end
  nil
end

 p two_sum([-1,-2,-3,-4,-5], -8)