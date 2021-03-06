// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "MavLinkConnection.hpp"
#include "impl/MavLinkConnectionImpl.hpp"

using namespace mavlinkcom;
using namespace mavlinkcom_impl;

MavLinkConnection::MavLinkConnection()
{
	pImpl.reset(new MavLinkConnectionImpl());
}

std::vector<SerialPortInfo> MavLinkConnection::findSerialPorts(int vid, int pid)
{
	return MavLinkConnectionImpl::findSerialPorts(vid, pid);
}

std::shared_ptr<MavLinkConnection>  MavLinkConnection::connectSerial(const std::string& nodeName, std::string portName, int baudrate, const std::string initString)
{
	return MavLinkConnectionImpl::connectSerial(nodeName, portName, baudrate, initString);
}

std::shared_ptr<MavLinkConnection>  MavLinkConnection::connectLocalUdp(const std::string& nodeName, std::string localAddr, int localPort)
{
	return MavLinkConnectionImpl::connectLocalUdp(nodeName, localAddr, localPort);
}

std::shared_ptr<MavLinkConnection>  MavLinkConnection::connectRemoteUdp(const std::string& nodeName, std::string localAddr, std::string remoteAddr, int remotePort)
{
	return MavLinkConnectionImpl::connectRemoteUdp(nodeName, localAddr, remoteAddr, remotePort);
}

std::shared_ptr<MavLinkConnection>  MavLinkConnection::connectTcp(const std::string& nodeName, std::string localAddr, const std::string& remoteIpAddr, int remotePort)
{
	return MavLinkConnectionImpl::connectTcp(nodeName, localAddr, remoteIpAddr, remotePort);
}

void MavLinkConnection::startListening(const std::string& nodeName, std::shared_ptr<Port> connectedPort)
{
	pImpl->startListening(shared_from_this(), nodeName, connectedPort);
}


// log every message that is "sent" using sendMessage.
void MavLinkConnection::startLoggingSendMessage(std::shared_ptr<MavLinkLog> log)
{
	pImpl->startLoggingSendMessage(log);
}

void MavLinkConnection::stopLoggingSendMessage()
{
	pImpl->stopLoggingSendMessage();
}

void MavLinkConnection::close()
{
	pImpl->close();
}

bool MavLinkConnection::isOpen()
{
    return pImpl->isOpen();
}

std::string MavLinkConnection::getName()
{
	return pImpl->getName();
}
int MavLinkConnection::getTargetComponentId()
{
	return pImpl->getTargetComponentId();
}
int MavLinkConnection::getTargetSystemId()
{
	return pImpl->getTargetSystemId();
}

uint8_t MavLinkConnection::getNextSequence()
{
	return pImpl->getNextSequence();
}
void MavLinkConnection::sendMessage(const MavLinkMessageBase& msg)
{
	pImpl->sendMessage(msg);
}
void MavLinkConnection::sendMessage(const MavLinkMessage& msg)
{
	pImpl->sendMessage(msg);
}

int MavLinkConnection::subscribe(MessageHandler handler)
{
	return pImpl->subscribe(handler);
}

void MavLinkConnection::unsubscribe(int id) 
{
	pImpl->unsubscribe(id);
}

MavLinkConnection::~MavLinkConnection() {
	pImpl->close();
	pImpl = nullptr;
}
void MavLinkConnection::join(std::shared_ptr<MavLinkConnection> remote, bool subscribeToLeft, bool subscribeToRight)
{
	pImpl->join(remote);
}

//MavLinkConnection::MavLinkConnection(MavLinkConnection&&) = default;
//MavLinkConnection& MavLinkConnection::operator=(MavLinkConnection&&) = default;
