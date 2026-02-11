*This project has been created as a part of the 42 curriculum by daxferna*

# Description
The **Net Practice** project focuses on learning how computer networking works.\
Consisting on 10 levels, it presents students with incorrectly configured network diagrams that they must fix.\
The purpose of the project is to introduce the student to concepts such as TCP/IP addressing, routers and switches or gateways.
# Instructions
Once the tar file attached to the project's page has been downloaded and extracted, you have to run the `index.html` file.\
This file will prompt an interface in which you can choose between practice and evaluation mode. You should enter your intra login in order for the configuration files to be correct.\
The interface will show clues on why the configuration is not working on the bottom right.\
Once a level has been completed, a configuration file must be exported by clicking `Get my config`. The student has to submit 10 configuration files corresponding to each exercise, which will be placed at the repository root.\
During the evaluation, the student has to fix 3 random network diagrams in 15 minutes or less.
# Resources
### Concepts

- **IP Address:** \
	Identifier for a computer or device on a network. It makes possible the communication between devices.\
	Format: 4 octets of bits (0-255).\
	For example, `192.168.1.3`.\
	It consists of two parts:
	- Network address: number assigned to a network
	- Host address: number assigned to each host in that network
	To distinguish each part, we have to look at the **subnet mask**.

When a device wants to communicate with another device within a network, it sends a broadcast to every device so the target identifies itself.\
This is easy in small networks, but when we have a large one, with many computers broadcasting at the same time, it leads to slow traffic and even a halt.\
Thats why networks need to be broken down into smaller ones, this is called subnetting and its possible thanks to routers, switches and subnet mask.
- **Subnet mask:** \
	IP-like address that lets you know which part of the IP is the network IP and which is the host IP.\
	It has also 4 octets of bits from 0 to 255 each\
	When converted to binary, the **ones** indicate the *network* and the **zeros** indicate the *host*\
	For example
	<pre>
	   255  .   255  .   255  .   0
	11111111.11111111.11111111.00000000</pre>
	means the first three octets identify the network address and the last one, the host address, so we have 254 available hosts (0 and 255 are reserved)\
	But in this one, it's trickier
	<pre>
	   255  .   255  .   240  .   0
	11111111.11111111.11110000.00000000</pre>
	the first 2 octets and the first part of the third octet are part of the network address.

- **Routers:** \
	Devices that allow to subdivide a network.\
	If we have the subnet mask `255.255.255.0`(254 hosts), we can divide it in, lets say, 2 subnets.\
	Our new mask will be `255.255.255.127`:
	- First subnet `255.255.255.1` - `255.255.255.126` (126 hosts)
	- Second subnet `255.255.255.129` - `255.255.255.254`(126 hosts)

- **Switches:** \
	It allows you to connect multiple devices within the same network, it has no interface.

- **TCP/IP Addressing:** \
	It's a group of communication protocols used in networking\

	TCP (Transmission Control Protocol): Ensures reliable data transmission between devices.
	TCP/IP is based on 4 layers:

	- Application Layer: Manages applications.
	- Transport Layer: Ensures data delivery.
	- Internet Layer: Handles addressing and routing.
	- Network Access Layer: Manages physical transmission.

- **Default gateway:** \
	It's the IP that belongs to the network router, which gives every device an IP address, it gets the second possible IP address in the IP range.\
	For example, in  network with this subnet:\
	`255.255.255.0`\
	the default gateway could be:\
	`192.168.1.1`\
	It also gives every device access to the internet.

- **OSI layers:** \
	Seven‑layer reference model (Physical, Data Link, Network, Transport, Session, Presentation, Application) used to conceptualize network functions.

### Documentation
- **YouTube tutorials:** \
[Subnet mask](http://youtube.com/watch?v=s_Ntt6eTn94&list=PLCXqoZAc8-tzD5N5oCyIyEcMg_NDs6o7C)\
[IP Addresses playlist](https://www.youtube.com/watch?v=5WfiTHiU4x8&list=PLIhvC56v63IKrRHh3gvZZBAGvsvOhwrRF)
- **Articles** \
[Computer networks](https://www.freecodecamp.org/news/computer-networks-and-how-to-actually-understand-them-c1401908172d/)
[Wikipedia OSI Model](https://en.wikipedia.org/wiki/OSI_model)
