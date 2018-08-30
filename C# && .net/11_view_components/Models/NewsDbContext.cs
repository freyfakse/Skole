using Microsoft.EntityFrameworkCore;

namespace Models
{
    public class NewsDbContext : DbContext
    {
        // This constructor is required so you can register the db context as a service in Startup.cs.
        public NewsDbContext(DbContextOptions<NewsDbContext> options) : base(options)
        { }

        public DbSet<Article> Articles { get; set; }
    }
}
