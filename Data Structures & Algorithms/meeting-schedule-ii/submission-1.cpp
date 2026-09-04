/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }



 1. sort intervals
 2. results = size of intervals
 2. make min heap
 3. iterate over intervals 
 => get min heap, if intervals[0] > min heap => pop the element, subtract result by 1
 => add back to the heap
 this way we always put a meeting ontop of the closest time  (greedy)
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            if (a.start == b.start) {
                return a.end < b.end; // Tie-breaker: sort by end time if starts are equal
            }
            return a.start < b.start; // Primary: sort by start time
        });
        int result = intervals.size();
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        int curr;
        for(int i = 0; i < intervals.size(); i++){
            if(minHeap.size() == 0){
                minHeap.push(intervals[i].end);
            }else{
                curr = minHeap.top();
                if(curr <= intervals[i].start){
                    minHeap.pop();
                    result--;
                }
                minHeap.push(intervals[i].end);

            }
            
        }
        return minHeap.size();
    }
};
