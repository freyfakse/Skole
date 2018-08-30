using System.Collections.Generic;

namespace Example.Models
{
    public class Student
    {
        public Student()
        {
            Grades = new List<CourseGrade>();
        }

        public Student(string firstName, string lastName)
        {
            this.FirstName = firstName;
            this.LastName = lastName;

            Grades = new List<CourseGrade>();
        }

        // Basic properties of a student
        public int Id { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }

        // Each student has a list of results.
        // These will be put in a seperate table in the database automatically.
        public List<CourseGrade> Grades { get; set; }
    }   
}
