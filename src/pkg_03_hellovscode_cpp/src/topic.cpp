//包含头文件


//调用自定义类指针
//创建消息发布方
//回掉函数

#include"rclcpp/rclcpp.hpp"
#include"std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

//3.自定义节点类
class Talker: public rclcpp::Node{//声明一个发布方类//talker类从Node类中派生

public:





  Talker():Node("talker node cpp"){//talker构造函数，将节点命名为talker node cpp

    RCLCPP_INFO(this->get_logger(),"发布节点创建");//日志






    
    //3-1 创建消息发布方
    publisher_=this->create_publisher<std_msgs::msg::String>("chatter",10);//队列深度为10
                                        //如果发不出，存在队列里面

          /*

    this->create_publisher: 
    这是rclcpp::Node类的一个成员函数，用于在当前节点上创建一个新的发布者。
  

    <std_msgs::msg::String>: 
    模板参数，指定了发布者将要发布的消息的类型。
    发布者将发布std_msgs::msg::String类型的消息，这是一个ROS标准消息类型，包含一个字符串。

    "chatter": 自己取的，主题

    10:  QOS
    队列长度
    如果订阅者不能立即接收消息，发布者会把最多10个消息存储在队列中
*/


    //3-2创建定时器
    this->create_wall_timer(1s,std::bind(&Talker::on_timer),this);
    /*this->create_wall_timer:函数
    三个参数：时间（现在不知到是什么时间）
    bind:
    this:接收的指针
    */
    
  }



private:
  void on_timer(){
    auto message
  };
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};


int main(int argc,char** argv){
  //初始化客户端
  rclcpp::init(argc,argv);
  //调用spin函数
  rclcpp::spin(std::make_shared<Talker>());
  //释放资源"
  rclcpp::shutdown();
}