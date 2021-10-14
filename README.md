Test push code at home!


git add <file_path>
git commit
git push -u origin master
git pull origin master

if git push timeout, use below command to avoid ssl verify:
 git config --global http.sslVerify "false"