cat << EOL > "/c/Users/ByteByByte/send.txt"
anonymous
cd /home/lvuser/
put "C:\Users\ByteByByte\vsc\DeepSpace\src\params.txt"
bye
EOL

ftp -s:/c/Users/ByteByByte/send.txt 10.43.9.2
rm /c/Users/ByteByByte/send.txt