# Write your MySQL query statement below
SELECT (SELECT DISTINCT salary as SecondHighestSalary FROM Employee ORDER BY salary DESC LIMIT 1,1) AS SecondHighestSalary;