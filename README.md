# Flight Monitor
Flight Monitor module of Ground Control Station for drones developed with Qt 5 on Windows 7

### 运行效果图

飞前监控

![](https://raw.githubusercontent.com/strawdiving/DroneGroundStation/master/runImages/2.PNG)

### 程序结构

- mainwindow：飞行监控主页面，显示

  | 飞行信息                   | 飞机的状态信息       |
  | -------------------------- | -------------------- |
  | 飞行模式                   | 连接状态             |
  | 飞行姿态（roll/pitch/yaw） | 遥控信号             |
  | 飞行时间                   | GPS信号              |
  | 飞行高度                   | 电量（及低电量报警） |
  | 飞行速度                   | Arm状态              |
  | 飞行距离                   | 飞行状态             |

- attitude_indicator：实时绘图显示飞行器姿态信息
- audio_worker：语音报警功能
- Vehilce：从收到的MAVLink消息包中解析出飞行信息和飞机的状态信息，发送给mainwindow进行显示
- VehicleManager： 管理vehicle的创建和销毁
- LinkManager：管理串口连接，从串口数据中读取完整的MAVLink消息包，转发给Vehicle进行进一步处理
- SerialCommunication：串口收发线程

### 程序流程

1. 主页面点击“连接”按钮，在串口列表中搜寻到对应飞控，连接
2. 飞控连接地面站后，持续发送固定的消息包（发送哪些消息包以及发送频率由飞控开发人员定义）
3. 地面站通过串口线程持续地接收数据
4. 接收到的数据交给LinkManager，提取出完整的MAVLink消息包
5. 地面站通过Heartbeat（#0）心跳包监测飞控的连接状态
6. LinkManager将MAVLink消息包转发给Vehicle，Vehicle提取所需的信息在主页面进行显示