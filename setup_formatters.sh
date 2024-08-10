# Install formatters
pkg install openjdk-17
wget https://github.com/google/google-java-format/releases/download/v1.15.0/google-java-format-1.15.0-all-deps.jar -O /usr/local/bin/google-java-format.jar

pkg install clang

pkg install python
pip install black

pkg install nodejs
npm install -g prettier

# Edit Nano configuration
cat <<EOL >> ~/.nanorc

## Java Formatter
bind ^J format java "java -jar /usr/local/bin/google-java-format.jar -i" ^T

## C Formatter
bind ^C format c "clang-format -i" ^T

## Python Formatter
bind ^P format python "black" ^T

## JavaScript Formatter
bind ^K format javascript "prettier --write" ^T
EOL
