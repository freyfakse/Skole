using System;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Logging;
using Example.Models;
using Microsoft.EntityFrameworkCore;
using System.Net.Http;
using System.Threading.Tasks;

namespace Example
{
    public class Startup
    {
        public Startup(IHostingEnvironment env)
        {
            var builder = new ConfigurationBuilder()
                .SetBasePath(env.ContentRootPath)
                .AddJsonFile("appsettings.json", optional: true, reloadOnChange: true)
                .AddJsonFile($"appsettings.{env.EnvironmentName}.json", optional: true)
                .AddEnvironmentVariables();
            Configuration = builder.Build();
        }

        public IConfigurationRoot Configuration { get; }

        // This method gets called by the runtime. Use this method to add services to the container.
        public void ConfigureServices(IServiceCollection services)
        {
            // We configure the database type and options here.
            // For SQLite all we need is a filename.
            services.AddDbContext<StudentDbContext>(options => options.UseSqlite("Filename=./Blogging.db"));

            // Add framework services.
            services.AddMvc();
        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IHostingEnvironment env, ILoggerFactory loggerFactory)
        {
            loggerFactory.AddConsole(Configuration.GetSection("Logging"));
            loggerFactory.AddDebug();

            if (env.IsDevelopment() || true)
            {
                app.UseDeveloperExceptionPage();
                app.UseBrowserLink();

                // Recreate the database every time the server is restarted.
                // Keeps the database clean while testing.
                using (var serviceScope = app.ApplicationServices.GetRequiredService<IServiceScopeFactory>().CreateScope())
                {
                    var db = serviceScope.ServiceProvider.GetService<StudentDbContext>();
                    
                    db.Database.EnsureDeleted();
                    db.Database.EnsureCreated();

                    // Link to hand-in sheet as CSV
                    var handInSheet = "https://docs.google.com/spreadsheets/d/1lkidKSdXj3UhfGOZ-vpn2_vIwW5NzM3QLaSSRChaf-I/export?format=csv";

                    // Download the hand-in sheet
                    var client = new HttpClient();
                    var students = client.GetAsync(handInSheet).Result.Content.ReadAsStringAsync().Result;

                    // Parse the CSV and add every student listed in it to the database
                    foreach (var s in students.Split('\n'))
                        db.Students.Add(new Models.Student(s.Split(',')[1], s.Split(',')[2]));

                    // We need to save changes before adding grades to make sure the students exist
                    db.SaveChanges();

                    var grades = "ABCDEF";
                    var random = new Random(); // Used to generate random grades

                    // Add random grades to the students
                    foreach (var s in db.Students)
                    {
                        s.Grades.Add(new CourseGrade("DAT219", grades[random.Next(0, 6)]));
                        s.Grades.Add(new CourseGrade("DAT220", grades[random.Next(0, 6)]));
                    }

                    db.SaveChanges();
                }
            }
            else
            {
                app.UseExceptionHandler("/Home/Error");
            }

            app.UseStaticFiles();

            app.UseMvc(routes =>
            {
                routes.MapRoute(
                    name: "default",
                    template: "{controller=Home}/{action=Index}/{id?}");
            });
        }
    }
}
