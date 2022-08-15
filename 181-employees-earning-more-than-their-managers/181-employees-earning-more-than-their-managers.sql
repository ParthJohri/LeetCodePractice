# Write your MySQL query statement below
SELECT name as Employee FROM Employee E WHERE  salary > (SELECT salary FROM Employee  m WHERE m.id=E.managerID)  ;