using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class UserIdGetter
    {
        public int GetUserId(string name)
        {
            BookEventContext bookEventContext = new BookEventContext();
            UserBO userBO = new UserBO();

            bookEventContext.Database.Log = Console.Write;
            int Id = bookEventContext.UserBOs.Where(a => a.UserName == name).Select(a => a.UserID).FirstOrDefault();
            return Id;
        }
    }

}
