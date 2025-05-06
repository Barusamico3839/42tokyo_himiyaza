num1=$(find . -type f | wc -l)
num2=$(find . -type d | wc -l)
num3=$((num1 + num2))
echo "$num3"

find .  -type f -o -type d  | wc -l