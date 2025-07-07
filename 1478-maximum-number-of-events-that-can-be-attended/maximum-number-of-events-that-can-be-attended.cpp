class Solution {
public:
    bool static comp(vector<int>& event1,vector<int>& event2)
    {
        return event1[0]<event2[0];
    }

    int maxEvents(vector<vector<int>>& events) {
        //we want to attend events ending sooner first, to leave room for future events - pick the event with the earliest end day that's still available
        int n=events.size(),i=0,count=0,day=1;
        sort(events.begin(),events.end(),comp); //sort events by start day so we cna process them in the order they become available
        priority_queue<int,vector<int>,greater<int>> pq; //create a min-heap to keep track of event end days, min-heap to pick earliest end day
        while (i<n || !pq.empty()) //loop while still events to process or heap has available events
        {
            while (i<n && events[i][0]==day) //today is the start day of some events
            {
                pq.push(events[i][1]); //push end days into heap, option to attend
                i++;
            }
            while (!pq.empty() && pq.top()<day)
                pq.pop(); //remove events that have already expired
            if (!pq.empty())
            {
                pq.pop(); //attend
                count++;
            }
            day++;
        }
        return count;        
    }
};

/*
class Solution {
public:
    bool static comp(vector<int>& event1,vector<int>& event2)
    {
        return event1[1]<event2[1];
    }

    int maxEvents(vector<vector<int>>& events) {
        int n=events.size(),maxi=0,count=0,set=0;
        sort(events.begin(),events.end(),comp);
        for (int i=0;i<n;i++)
            maxi=max(maxi,events[i][1]);
        vector<int> occupied(maxi+1,0);
        for (int i=0;i<n;i++)
        {
            set=0;
            for (int j=events[i][0];j<=events[i][1];j++)
            {
                if (occupied[j]==0)
                {
                    occupied[j]=1;
                    set=1;
                    break;
                }
            }
            if (set==1)
                count++;
        }
        return count;
    }
};
*/