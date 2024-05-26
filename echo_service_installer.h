#ifndef ECHO_SERVICE_INSTALLER_H
#define ECHO_SERVICE_INSTALLER_H

#include "address.h"
#include "echo_service.h"
#include "service_installer.h"

class EchoServiceInstaller : public ServiceInstaller {
private:
  // 패킷을 수신할 포트
  short listenPort_;

public:
  EchoServiceInstaller(short listenPort) : listenPort_(listenPort) {}

  // 호스트에 EchoService를 설치한다.
  EchoService *install(Host *host){
    Service *service = new Service(host, listenPort_);
    EchoService *echoService = new Service(host, listenPort_);    
    ServiceInstaller installer;
    installer.install(host, echoService);
  }
};

#endif