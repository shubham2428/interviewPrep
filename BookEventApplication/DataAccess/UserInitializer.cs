using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class UserInitializer:System.Data.Entity.DropCreateDatabaseIfModelChanges<BookEventContext>
    {
        protected override void Seed(BookEventContext context)
        {
            var users = new List<UserBO>
            {
                 
                new UserBO{UserID=1,UserName="Anshika",Password="anshika1",EmailId="anshika@nagarro.com",TypeOfUser="Admin"},
               new UserBO { UserID = 2, UserName = "Prakshita", Password = "prakshita2",EmailId="prakshita@nagarro.com",TypeOfUser="User" },
               new UserBO{UserID=3,UserName="Jaitley",Password="jaitley3",EmailId="jaitley@nagarro.com",TypeOfUser="User"},
               new UserBO{UserID=4,UserName="Apoorva",Password="apoorva4",EmailId="apoorva@nagarro.com",TypeOfUser="User"}

            };
            users.ForEach(s => context.UserBOs.Add(s));
            context.SaveChanges();

           


        }

    }
   
}
