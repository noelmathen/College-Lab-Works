# Internetworking Basics

## Cycle 1: Internetworking Basics

### 1. Familiarization of Network Hardware Devices
Understand the different types of network hardware devices and their purposes:
- **Network Interface Card (NIC)**: Enables a computer to connect to a network.
- **Hub**: A basic device that connects multiple computers in a network, operating at the Physical Layer (Layer 1) of the OSI model.
- **Switch**: Connects devices within a network and forwards data to the correct destination using MAC addresses, operating at the Data Link Layer (Layer 2).
- **Router**: Connects multiple networks and routes data between them, operating at the Network Layer (Layer 3).
- **Access Point (AP)**: Extends a wired network to include wireless devices, operating at the Data Link Layer (Layer 2).
- **Modem**: Modulates and demodulates signals for data transmission over telephone lines, cable, or satellite, connecting a network to the Internet.

### 2. Familiarization of Network Cables and Connectors
Learn about the different types of network cables and connectors:
- **Ethernet Cables**:
  - **Cat5e**: Supports speeds up to 1 Gbps.
  - **Cat6**: Supports speeds up to 10 Gbps over short distances.
  - **Cat6a**: Enhanced Cat6, supports 10 Gbps up to 100 meters.
  - **Cat7**: Supports speeds up to 10 Gbps with shielding for reduced interference.
- **Fiber Optic Cables**:
  - **Single-mode**: Long-distance transmission with a single light path.
  - **Multi-mode**: Shorter distances with multiple light paths.
- **Coaxial Cables**: Used for cable television and Internet connections.
- **Connectors**:
  - **RJ45**: Common connector for Ethernet cables.
  - **LC, SC, ST**: Common connectors for fiber optic cables.
  - **BNC**: Used with coaxial cables for video and RF connections.

### 3. Familiarization of Colour Coding and Crimping
Understand the standards for cable color coding and learn how to crimp cables:
- **TIA/EIA 568A and 568B Standards**:
  - **568A**: White/Green, Green, White/Orange, Blue, White/Blue, Orange, White/Brown, Brown.
  - **568B**: White/Orange, Orange, White/Green, Blue, White/Blue, Green, White/Brown, Brown.
- **Crimping Steps**:
  1. Strip about 2 inches of the outer jacket of the Ethernet cable.
  2. Untwist and arrange the wires according to the 568A or 568B standard.
  3. Trim the wires evenly and insert them into the RJ45 connector.
  4. Use the crimping tool to secure the connector onto the cable.

### 4. Internetworking Operating Systems - Configurations
Learn how to configure networking settings on different operating systems:
- **Configuring IP Addresses**:
  - **Static IP Configuration**:
    - **Linux**: Edit `/etc/network/interfaces` or use `nmcli`.
    - **Windows**: Use the Network and Sharing Center or `netsh` command.
  - **Dynamic IP Configuration (DHCP)**: Ensure the device is set to obtain an IP address automatically from a DHCP server.
- **Configuring DNS**:
  - **Linux**: Edit `/etc/resolv.conf`.
  - **Windows**: Use the Network and Sharing Center or `netsh` command.
- **Configuring Hostname**:
  - **Linux**: Use `hostnamectl set-hostname newhostname` or edit `/etc/hostname`.
  - **Windows**: Use the System Properties or `hostname` command.

### 5. Study of TCP/IP Protocol Suite
Understand the TCP/IP protocol suite and its components:
- **TCP (Transmission Control Protocol)**: Provides reliable, ordered, and error-checked delivery of data.
- **IP (Internet Protocol)**: Handles addressing and routing of packets between devices.
  - **IPv4**: 32-bit addresses (e.g., 192.168.1.1).
  - **IPv6**: 128-bit addresses (e.g., 2001:0db8:85a3:0000:0000:8a2e:0370:7334).
- **UDP (User Datagram Protocol)**: Provides a simpler, connectionless communication model without delivery guarantees.
- **ICMP (Internet Control Message Protocol)**: Used for error messages and operational queries (e.g., `ping`).

### 6. Familiarization of Cisco Hub, Switch, Router, Access Point Commands
Learn basic commands for configuring Cisco networking devices:
- **Accessing the Device**:
  - **Console Access**: Connect via console cable and use a terminal emulator (e.g., PuTTY).
  - **SSH/Telnet**: Secure or unsecure remote access.
- **Basic Commands**:
  - **Entering Enable Mode**: `enable`
  - **Entering Configuration Mode**: `configure terminal`
- **Configuring Interfaces**:
  - **Setting an IP Address on an Interface**:
    ```sh
    interface GigabitEthernet0/1
    ip address 192.168.1.1 255.255.255.0
    no shutdown
    ```
- **Viewing Configuration**: `show running-config`
- **Saving Configuration**: `copy running-config startup-config`
- **VLAN Configuration (Switch)**:
  - **Creating a VLAN**:
    ```sh
    vlan 10
    name Sales
    ```
  - **Assigning an Interface to a VLAN**:
    ```sh
    interface GigabitEthernet0/1
    switchport mode access
    switchport access vlan 10
    ```
- **Routing Configuration (Router)**:
  - **Static Route**:
    ```sh
    ip route 192.168.2.0 255.255.255.0 192.168.1.2
    ```
- **Access Point Configuration**:
  - **Setting SSID**:
    ```sh
    interface Dot11Radio0
    ssid MyNetwork
    ```
