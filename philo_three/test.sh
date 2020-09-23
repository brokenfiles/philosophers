MAX_TEST=1000
TEST=0
SLEEP=0

echo '> Reloading project...'
make > /dev/null
while [ "$MAX_TEST" -ge "$TEST" ]; do
  sleep $SLEEP
  cat /dev/null > user.output
  ./philo_three 3 201 100 100 > user.output
  RETURN=$(grep -c "died" < user.output | awk '{ print $1 }')
  if [ "$RETURN" != "1" ]; then
    echo "[KO] ! RETURN = $RETURN"
    exit 1
  else
    printf "[OK] $TEST / $MAX_TEST (%.0f%%)\n" $( bc <<< "scale=2; ($TEST/$MAX_TEST)*100")
  fi
  TEST=$((TEST+1))
  done
exit 0