2024.5.17 �����û���user
CREATE TABLE user(  
    id int NOT NULL PRIMARY KEY AUTO_INCREMENT, //�û�id��Ϊ�գ�������
    account_name VARCHAR(11) UNIQUE NOT NULL,   //�û������绰����, Ψһ�Ҳ�Ϊ��
    index idx_account_name(account_name),       //�����û���Ϊ�����������ٶȿ�
    username VARCHAR(32),                       //�û�����ע���¼�ɹ�ʱ����
    online_status int DEFAULT 0,                //�û�����״̬,Ĭ��Ϊ0�û�������
	assword VARCHAR(10) NOT NULL                //�û�����,��Ϊ��
) ;