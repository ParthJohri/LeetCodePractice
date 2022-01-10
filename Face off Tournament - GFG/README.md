# Face off Tournament
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Ram and Rohan are participating in a tournament. Together they must face off against x contenders whose strengths are given in an array arr[]. The respective strength of Ram and Rohan in m and n. They take turns taking part in face-off matches with contenders and Ram goes first. They win a match only if their opponent's strength is an integral multiple of their strengths. If the opponent is defeated, he can not fight again. </span></p>

<p><span style="font-size:18px">Find out who among Ram and Rohan is a better player. If both of them win the same number of matches then both are winners.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>
x = 7
m = 2, n = 3
arr = {4, 5, 7, 6, 9, 10, 14}
<strong>Output:</strong> Ram
<strong>Explaination:</strong> Ram win against opponents 
having strength 4, 6, 10, 14 and Rohan 
win against opponent having strength 9.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>
x = 6
m = 5, n = 3
arr = {1, 9, 9, 10, 9, 18}
<strong>Output:</strong> Rohan
<strong>Explaination:</strong> Ram win against opponent 
having strength 10 and Rohan win against 
three opponents having strength 9 and one 
having strength 18.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>winner()</strong> which takes x, m, n and arr as input parameters and returns one of the strings from {"Ram", "Rohan", "Both"} based on the answer.&nbsp;</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(x)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ x, n, m ≤ 10<sup>5</sup><br>
1 ≤ arr[i] ≤ 10<sup>18</sup> &nbsp;</span></p>
 <p></p>
            </div>