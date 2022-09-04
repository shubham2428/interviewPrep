using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Data.Entity.ModelConfiguration.Conventions;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class BookEventContext:DbContext
    {
        public BookEventContext():base("BookEventContext")
        {

        }
        public DbSet<UserBO> UserBOs { get; set; }
        public DbSet<EventsBO> EventsBOs { get; set; }
        

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Conventions.Remove<PluralizingTableNameConvention>();
        }

    }
}
