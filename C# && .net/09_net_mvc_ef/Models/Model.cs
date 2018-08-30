using Microsoft.EntityFrameworkCore;
using System.Collections.Generic;

namespace Example.Models
{
    public class BloggingContext : DbContext
    {
        // This constructor is required so you can register the db context as a service in Startup.cs.
        public BloggingContext(DbContextOptions<BloggingContext> options) : base(options)
        { }

        // Each DbSet will become a database table automatically
        public DbSet<Blog> Blogs { get; set; }
        public DbSet<Post> Posts { get; set; }
    }

    // Each class instance added to the db context will become a table row automatically
    public class Blog
    {
        public int BlogId { get; set; }
        public string Url { get; set; }

        public List<Post> Posts { get; set; }
    }

    public class Post
    {
        public int PostId { get; set; }
        public string Title { get; set; }
        public string Content { get; set; }

        public int BlogId { get; set; }
        public Blog Blog { get; set; }
    }
}

