using BusinessObjects;
using DataAccess;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BusinessLogics
{
    public class UserBL
    {


        public string AddUser(UserBO userBO)
        {
            if (!(new IsUser().IsAlreadyUser(userBO)))
            {
                return new UserAdder().AddUser(userBO);
            }

            return "UserName already exists";
        }
        public bool IsAuthenticatedUser(UserBO userBO)
        {
            return new IsUser().IsAuthenticatedUser(userBO);
        }

        public int GetUserId(string name)
        {
            return new UserIdGetter().GetUserId(name);
        }
        public List<EventsBO> GetEvents(int id)
        {
            return new EventsGetter().GetEvents(id);
        }

        public string GetUserEmail(string name)
        {
            return new UserEmailGetter().GetUserEmail(name);
        }

        public bool IsAdminUser(UserBO userBO)
        {
            return new IsAdmin().IsAdminUser(userBO);
        }

        public string GetUserType(string name)
        {
            return new UserTypeGetter().GetUserType(name);

        }



       
    }
}