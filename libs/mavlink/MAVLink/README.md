### 自定义Mavlink消息包

添加了遥控器校准相关的消息包（#150）：

| message id | name           | description                 |
| ---------- | -------------- | --------------------------- |
| 150        | param_calib_rc | the max and min value of RC |

![1545201299215](C:\Users\wurenji.ZKXS\AppData\Roaming\Typora\typora-user-images\1545201299215.png)

添加了PID调参相关的消息包（#151——#157）：

| message id | name               | description                                                  |
| ---------- | ------------------ | ------------------------------------------------------------ |
| 151        | Attitude_PITCH_PID | PID parameters of Attitude PITCH                             |
| 152        | Attitude_ROLL_PID  | PID parameters of Attitude ROLL                              |
| 153        | Attitude_YAW_PID   | PID parameters of Attitude Yaw                               |
| 154        | Position_X_PID     | PID parameters of Position X                                 |
| 155        | Position_Y_PID     | PID parameters of Position Y                                 |
| 156        | Position_Z_PID     | PID parameters of Position Z                                 |
| 157        | PID_SET_Confirm    | The message is sent to the GCS by quadrotor when the PID parameters are set. |

其中，151~156采用地面站向飞控单向发送的模式，飞控接收到消息包后解码，把数据提取出来对相应参数进行设置即可；157采用飞控向地面站单向发送的模式，当飞控中PID参数设置好以后，将参数发送给地面站以确认设置成功。

### 重新定义的Message

#### Heartbeat (#0)

message的结构不变。

| param         | value-description                                            |
| ------------- | ------------------------------------------------------------ |
| base_mode     | 2 - 手动，3 - 定高，4 - 定点                                 |
| custom_mode   | 0 - disarmed，1 - armed                                      |
| system_status | 0 - Landed，1 - Initiating，2-Taking off，4 - Flying，5 - Hovering，6 - FreeFall，7 - UpsideDown，8 - Tumble |

