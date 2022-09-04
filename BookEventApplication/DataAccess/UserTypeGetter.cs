using BusinessObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccess
{
    public class UserTypeGetter
    {
        public string GetUserType(string name)
        {
            BookEventContext bookEventContext = new BookEventContext();
            UserBO userBO = new UserBO();


            string UserType = bookEventContext.UserBOs.Where(a => a.UserName == name).Select(a => a.TypeOfUser).FirstOrDefault();
            return UserType;
        }
    }
}
