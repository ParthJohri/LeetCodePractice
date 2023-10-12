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
    int ascending(int target, MountainArray &mountainArr,int m){
        int n=mountainArr.length();
        int start=0,end=m,ans=-1;
        while(start<=end and start>=0 and end<=m){
            int mid=start+(end-start)/2;
            int ele=mountainArr.get(mid);
            if(ele==target){
                ans=mid;
                end=mid-1;
            }
            else if(ele>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    int descending(int target, MountainArray &mountainArr,int m){
        int n=mountainArr.length();
        int start=m,end=n-1,ans=-1;
        while(start<=end and start<n and end>=m){
            int mid=start+(end-start)/2;
            int ele=mountainArr.get(mid);
            if(ele==target){
                ans=mid;
                start=mid+1;
            }
            else if(ele>target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int start=0,end=n-1,ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int ele=mountainArr.get(mid);
                if(mid!=0 and mid!=n-1 and mountainArr.get(mid+1)<ele and ele>=mountainArr.get(mid-1)){
                    int x=ascending(target,mountainArr,mid);
                    int y=descending(target,mountainArr,mid);
                    if(x!=-1 and y!=-1) return min(x,y);
                    ans=max(x,y);
                    return ans;
                }
                else if(mid==n-1) {
                    end=mid-1;
                }
                else if(mid==0 or mountainArr.get(mid+1)>=ele and ele>=mountainArr.get(mid-1)){
                    start=mid+1;
                }
                else end=mid-1;
        }
        return ans;
    }
};