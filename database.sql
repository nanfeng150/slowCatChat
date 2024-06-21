2024.5.17 创建用户表user
CREATE TABLE user(  
    id int NOT NULL PRIMARY KEY AUTO_INCREMENT, //用户id不为空，自增长
    account_name VARCHAR(11) UNIQUE NOT NULL,   //用户名即电话号码, 唯一且不为空
    index idx_account_name(account_name),       //设置用户名为索引，查找速度快
    username VARCHAR(32),                       //用户名，注册登录成功时设置
    online_status int DEFAULT 0,                //用户在线状态,默认为0用户不在线
	assword VARCHAR(10) NOT NULL                //用户密码,不为空
) ;

