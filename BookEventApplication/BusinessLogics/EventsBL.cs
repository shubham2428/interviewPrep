using BusinessObjects;
using DataAccess;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BusinessLogics
{
    public class EventsBL
    {
        public string EventAdder(EventsBO eventsBO, int id, string name)
        {
            return new EventAdder().AddEvent(eventsBO, id, name);
        }


        public EventsBO EventsEditor(int id)
        {
            return new EventsEditor().EventsEditing(id);
        }


        public string UpdateEvents(EventsBO eventsBO)
        {
            return new EventsUpdator().UpdateEvents(eventsBO);
        }


        public IEnumerable<EventsBO> EventsInvitedTo(string Email)
        {
            return new EventsInvitedTo().EventsInvited(Email);
        }


        public List<EventsBO> GetAllEvents()
        {
            return new EventsGetter().GetAllEvents();
        }
        public IEnumerable<EventsBO> GetThisEvents(int id)
        {
            return new EventsGetter().GetThisEvents(id);
        }

        public List<EventsBO> GetFutureEvents()
        {
            return new FuturePublicEventsGetter().GetFutureEvents();
        }

        public List<EventsBO> GetPastEvents()
        {
            return new PastPublicEventsGetter().GetPastEvents();
        }

       
    }
}