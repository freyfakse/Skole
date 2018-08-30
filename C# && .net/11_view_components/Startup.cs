using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Logging;
using Microsoft.EntityFrameworkCore;
using System.Collections.Generic;
using Models;

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
            services.AddDbContext<NewsDbContext>(options => options.UseSqlite("Filename=./News.db"));

            // Add framework services.
            services.AddMvc();
        }

        // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
        public void Configure(IApplicationBuilder app, IHostingEnvironment env, ILoggerFactory loggerFactory)
        {
            loggerFactory.AddConsole(Configuration.GetSection("Logging"));
            loggerFactory.AddDebug();

            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();
                app.UseBrowserLink();

                // Recreate the database every time the server is restarted.
                // Keeps the database clean while testing.
                using (var serviceScope = app.ApplicationServices.GetRequiredService<IServiceScopeFactory>().CreateScope())
                {
                    var db = serviceScope.ServiceProvider.GetService<NewsDbContext>();
                    
                    db.Database.EnsureDeleted();
                    db.Database.EnsureCreated();

                    // Add some articles
                    db.Articles.AddRange(new List<Article>() {
                        new Article("Bjørndalen mest glad for konas medalje", "– En lettelse for familien.", "https://gfx.nrk.no/front/2017/02/12/c=1079,557,908,631;w=308;h=214;136465.jpg"),
                        new Article("Måtte stå i kø for å skyte", "– Kaos-VM fortsetter.", "https://gfx.nrk.no/front/2017/02/12/c=176,24,733,412;w=308;h=173;136469.jpg"),
                        new Article("Speilglatte veier", "Politiet i Nordland advarer bilister.", "https://gfx.nrk.no/front/2017/02/12/c=309,137,1205,771;w=308;h=197;136478.jpg")
                    });

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
