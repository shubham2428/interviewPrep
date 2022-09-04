using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class IsUser
    {
     
        public bool IsAlreadyUser(UserBO userBO)
        {
            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;

            bool isValid = bookEventContext.UserBOs.Any(x => x.UserID == userBO.UserID || x.UserName == userBO.UserName);
            if (isValid)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public bool IsAuthenticatedUser(UserBO userBO)
        {
           

            BookEventContext bookEventContext = new BookEventContext();
            bookEventContext.Database.Log = Console.Write;

            bool isValid = bookEventContext.UserBOs.Any(x => x.UserName == userBO.UserName && x.Password == userBO.Password && x.EmailId==userBO.EmailId && x.TypeOfUser==userBO.TypeOfUser);
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
