namespace Example.Models
{
    // The test result for one student for one test.
    public class CourseGrade
    {
        public CourseGrade() {}
        public CourseGrade(string course, char grade)
        {
            this.Course = course;
            this.Grade = grade;
        }

        public int Id { get; set; }

        // Create a compound unique key for course results
        //[Index("CourseAndGrade"), 1, IsUnique = true]
        public string Course { get; set; }

        //[Index("CourseAndGrade"), 2, IsUnique = true]
        public char Grade { get; set; }
    }   
}
