using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class IsAdmin
    {
        public bool IsAdminUser(UserBO userBO)
        {
            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;
            bool isValid = bookEventContext.UserBOs.Any(x => x.UserName =="admin" && x.Password =="admin01");
            if (isValid)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
