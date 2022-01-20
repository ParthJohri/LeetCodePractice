/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int start=0;
        int end=mountainArr.length()-1;
        int mid=0;
        int peak=0;
        
        while(start<end)
        {
            mid=start+(end-start)/2;
            
            if(mountainArr.get(mid)>mountainArr.get(mid+1))
            {
                end=mid;
            }
            else 
                start=mid+1;
        }
        peak=start;
        
        //first half
        start=0;
        end=peak;
        mid=0;
        bool b=mountainArr.get(start)<mountainArr.get(end);
        
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            if(b)
            {
                 if(target>mountainArr.get(mid))
                    start=mid+1;
                 else
                    end=mid-1;
            }
            else
            {
                if(target<mountainArr.get(mid))
                    start=mid+1;
                else
                    end=mid-1;
            }         
        }
        
        //second half
        start=peak+1;
        end=mountainArr.length()-1;
        mid=0;
        b=mountainArr.get(start)<mountainArr.get(end);
       
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            if(b)
            {
                 if(target>mountainArr.get(mid))
                    start=mid+1;
                 else
                    end=mid-1;
            }
            else
            {
                if(target<mountainArr.get(mid))
                    start=mid+1;
                else
                    end=mid-1;
            }         
        }
        
        return -1;
        
    }
    
};   