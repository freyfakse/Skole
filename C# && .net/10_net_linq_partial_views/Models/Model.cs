using Microsoft.EntityFrameworkCore;

namespace Example.Models
{
    public class StudentDbContext : DbContext
    {
        // This constructor is required so you can register the db context as a service in Startup.cs.
        public StudentDbContext(DbContextOptions<StudentDbContext> options) : base(options)
        { }

        // Each DbSet will become a database table automatically
        public DbSet<Student> Students { get; set; }
        public DbSet<CourseGrade> Results { get; set; }
    }
}
