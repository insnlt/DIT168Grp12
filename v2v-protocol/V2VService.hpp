/*
* @authors- Andrius Sakalas, Margit Saal, Karanveer Singh
* Group - 12
*/
#ifndef V2V_PROTOCOL_DEMO_V2VSERVICE_H
#define V2V_PROTOCOL_DEMO_V2VSERVICE_H

#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
#include "cluon/OD4Session.hpp"
#include "cluon/UDPSender.hpp"
#include "cluon/UDPReceiver.hpp"
#include "cluon/Envelope.hpp"
#include "Messages.hpp"
#include <iostream>
#include <queue>

/** ADD YOUR CAR_IP AND GROUP_ID HERE:  *****************/

static const std::string YOUR_CAR_IP    = "192.168.43.212";
static const std::string YOUR_GROUP_ID  = "12";

/********************************************************/
/** DON'T CHANGE STUFF BELOW THIS LINE. *****************/
/********************************************************/

static const int BROADCAST_CHANNEL = 250;
static const int DEFAULT_PORT = 50001;
static const int INTERNAL_CHANNEL = 230;    // Group - 12 CID

static const int ANNOUNCE_PRESENCE = 1001;
static const int FOLLOW_REQUEST = 1002;
static const int FOLLOW_RESPONSE = 1003;
static const int STOP_FOLLOW = 1004;
static const int LEADER_STATUS = 2001;
static const int FOLLOWER_STATUS = 3001;
static const int DELAY_ANGLE = 12 ;

static float PEDAL_SPEED;
static float GROUND_STEERING;


class V2VService {
public:
    std::map <std::string, std::string> presentCars;

    std::queue<float> angleQueue;
   
    V2VService();
    void carQueue(LeaderStatus leaderStatus);
    void announcePresence();
    void followRequest(std::string vehicleIp);
    void followResponse();
    void stopFollow(std::string vehicleIp);
    void leaderStatus(float speed, float steeringAngle, uint8_t distanceTraveled);
    void followerStatus();
    
private:
    std::string leaderIp;
    std::string followerIp;

    std::shared_ptr<cluon::OD4Session>  movement;
    std::shared_ptr<cluon::OD4Session>  broadcast;
    std::shared_ptr<cluon::UDPReceiver> incoming;
    std::shared_ptr<cluon::UDPSender>   toLeader;
    std::shared_ptr<cluon::UDPSender>   toFollower;
    
    std::shared_ptr<cluon::OD4Session>  internalService;

    static uint32_t getTime();
    static std::pair<int16_t, std::string> extract(std::string data);
    template <class T>
    static std::string encode(T msg);
    template <class T>
    static T decode(std::string data);
};

#endif //V2V_PROTOCOL_DEMO_V2VSERVICE_H
