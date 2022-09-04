using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class UserEmailGetter
    {
        public string GetUserEmail(string name)
        {
            BookEventContext bookEventContext = new BookEventContext();
            UserBO userBO = new UserBO();

            bookEventContext.Database.Log = Console.Write;
            string EmailId = bookEventContext.UserBOs.Where(a => a.UserName == name).Select(a => a.EmailId).FirstOrDefault();
            return EmailId;
        }
    }
}
