#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <vector>
#include <math.h>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

struct bot_info {
  int run_status,onesecondcounterbot,printcount;
  float location_x,location_y;
} ;
bot_info bots[5];
int z=0;
int distancecheck(float x1, float x2, float y1, float y2 ){
 if (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))>1) {
   return 0;
 }
 else{
    return 1;
 }
}
void chatterCallback(const std_msgs::String::ConstPtr& msg);

void init(){
for (int i = 1; i < 5; i++) {

  bots[i].run_status=1;
  bots[i].onesecondcounterbot=0;
  bots[i].printcount=0;
  bots[i].location_x=8178434;
  bots[i].location_y=8178434;
}
}

int main(int argc, char **argv)
{
init();
ros::init(argc, argv, "server");
ros::NodeHandle server;
ros::Publisher server_pub = server.advertise<std_msgs::String>("server_said", 1000);
ros::Subscriber server_sub = server.subscribe("bot_said", 1000, chatterCallback);
ros::Rate loop_rate(10);
ros::spin();

return 0;
}


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  std_msgs::String pub_str;
  std::stringstream ss;
  ss <<msg->data.c_str();
  pub_str.data=ss.str(); // recevied msg form "bot_said"

  using namespace boost::algorithm;
  std::string str = pub_str.data.c_str();

  std::vector<std::string> tokens;
  split(tokens, str, is_any_of(" ")); // split recevied string with spaces

  int bot_id=std::stoi(tokens[0]);
  bots[bot_id].location_x = std::stof(tokens[1]) ;
  bots[bot_id].location_y = std::stof(tokens[2]) ;

if (bots[bot_id].printcount==10) {
bots[bot_id].printcount=0;
  ROS_INFO("bot %d said mylocation is" , bot_id);
  std::cout << bots[bot_id].location_x <<"," << abs(bots[bot_id].location_y)<<std::endl;  // values from bot
}
bots[bot_id].printcount++;

  ros::NodeHandle server;
  ros::Publisher server_pub = server.advertise<std_msgs::String>("server_said", 1000);

if (bots[1].location_y !=8178434 && bots[2].location_y != 8178434 && bots[3].location_y != 8178434&& bots[4].location_y != 8178434)
{
int i=bot_id;
      for (int j = 1; j < 5; j++) {
            if (i!=j) {
          if (distancecheck(bots[j].location_x,bots[i].location_x,bots[j].location_y,bots[i].location_y) && bots[i].run_status) {
            std_msgs::String msg;
            std::stringstream ss;
            std_msgs::String msg1;
            std::stringstream ss1;
            ss << "stop" << " " << i;
            bots[i].run_status=0;
            msg.data = ss.str();
            server_pub.publish(msg);

            ss1 << "change_direction" << " " << i;
            msg1.data = ss1.str();
            server_pub.publish(msg1);

          }
        }
      }

      if (bots[i].run_status==0) {
        if (bots[i].onesecondcounterbot==10) {
          bots[i].onesecondcounterbot=0;
          std_msgs::String msg;
          std::stringstream ss;
          ss << "start" << " " << i;
          msg.data = ss.str();
          server_pub.publish(msg);

          bots[i].run_status=1;
        }
        bots[i].onesecondcounterbot++;
      }

      if (bots[bot_id].location_x<1 || bots[bot_id].location_x>29 || bots[bot_id].location_y>-1 || bots[bot_id].location_y<-29) {
        // ROS_INFO("%d,%d,%d,%d",(bots[i].location_x<1),(bots[i].location_x>29),(bots[i].location_y>-1),(bots[i].location_y<-29));
        std_msgs::String msg5;
        std::stringstream ss5;
        ss5 << "change_direction" << " " << bot_id;
        msg5.data = ss5.str();
        server_pub.publish(msg5);


      }


}



z++;
}
