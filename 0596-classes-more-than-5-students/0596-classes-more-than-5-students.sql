select s.class from Courses s 
group by s.class
having COUNT(s.student) >= 5;