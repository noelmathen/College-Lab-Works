# Cycle 2: Network Configuration Commands

## Study of Basic Network Command and Network Configuration Commands

### a. Ping
- **Purpose**: Tests the reachability of a host on an IP network and measures the round-trip time for messages sent.
- **Usage**:
  ```sh
  ping <hostname or IP address>
  ```
- **Example**:
  ```sh
  ping google.com
  ```
- **Explanation**: The `ping` command sends ICMP Echo Request packets to the target host and waits for ICMP Echo Reply packets. It reports the time taken for each packet to make the round trip.

- #### Output:
- ![ping output](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20CN%20(Computer%20Networks)/Cycle2%20-%20Network%20Configuration%20Commands/ping.png)



### b. traceroute
- **Purpose**: Displays the route packets take to a network host, showing each hop and the time taken.
- **Usage**:
  ```sh
  traceroute <hostname or IP address>
  ```
- **Example**:
  ```sh
  traceroute google.com
  ```
- **Explanation**: The `traceroute` command sends packets with gradually increasing TTL (Time to Live) values to discover the path packets take to reach the target host, listing each hop along the way.

- #### Output:
- ![traceroute output](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20CN%20(Computer%20Networks)/Cycle2%20-%20Network%20Configuration%20Commands/traceroute.png)


### c. arp
- **Purpose**: Displays and modifies the IP-to-Physical address translation tables used by the Address Resolution Protocol (ARP).
- **Usage**:
  ```sh
  arp [-options] [hostname or IP address]
  ```
- **Example**:
  ```sh
  arp -a
  ```
- **Explanation**: The `arp -a` command displays the current ARP table entries, showing IP addresses and their associated MAC addresses.

- #### Output:
- ![arp output](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20CN%20(Computer%20Networks)/Cycle2%20-%20Network%20Configuration%20Commands/arp%20-a.png)



### d. route
- **Purpose**: Displays and manipulates the IP routing table in the kernel.
- **Usage**:
  ```sh
  route [-options] [add/delete] [destination] [gateway]
  ```
- **Example**:
  ```sh
  route -n
  ```
- **Explanation**: The `route -n` command displays the routing table in numerical format, showing network destinations, gateways, and interface information.

- #### Output:
- ![route output](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20CN%20(Computer%20Networks)/Cycle2%20-%20Network%20Configuration%20Commands/route.png)



### e. netstat
- **Purpose**: Displays network connections, routing tables, interface statistics, masquerade connections, and multicast memberships.
- **Usage**:
  ```sh
  netstat [-options]
  ```
- **Example**:
  ```sh
  netstat -an
  ```
- **Explanation**: The `netstat -an` command lists all active network connections and listening ports in numerical format.

- #### Output:
- ![netstat output1](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20CN%20(Computer%20Networks)/Cycle2%20-%20Network%20Configuration%20Commands/netstat1.png)

- ![netstat output2](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20CN%20(Computer%20Networks)/Cycle2%20-%20Network%20Configuration%20Commands/netstat2.png)


### f. About /etc folder
- **Purpose**: Contains system-wide configuration files and shell scripts that initialize system settings.
- **Important Files**:
  - `/etc/hostname`: Contains the hostname of the system.
  - `/etc/hosts`: Maps hostnames to IP addresses for local name resolution.
  - `/etc/resolv.conf`: Specifies DNS servers for name resolution.
  - `/etc/network/interfaces`: Configures network interfaces on Debian-based systems.
- **Explanation**: The `/etc` directory is crucial for configuring various system and network settings, ensuring proper operation and connectivity.



### g. Setting up Hostname/Setting Local Name Resolution
- **Setting Hostname**:
  - **Linux**:
    ```sh
    sudo hostnamectl set-hostname <newhostname>
    ```
  - **Editing `/etc/hostname`**:
    ```sh
    sudo nano /etc/hostname
    ```
    Change the content to the new hostname.
  - **Windows**:
    - Open System Properties and change the hostname.
    - Use the command prompt:
      ```sh
      hostname <newhostname>
      ```
- **Setting Local Name Resolution**:
  - **Editing `/etc/hosts`**:
    ```sh
    sudo nano /etc/hosts
    ```
    Add an entry:
    ```sh
    <IP address> <hostname>
    ```
  - **Example**:
    ```sh
    127.0.0.1 mylocalmachine
    ```
- **Explanation**: Setting the hostname and configuring local name resolution allows the system to be identified on the network and resolve hostnames to IP addresses locally, which is essential for networking and accessing services efficiently.
