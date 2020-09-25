MAX_TEST=60
TEST=0
SLEEP=0

echo '> Reloading project...'
make > /dev/null
while [ "$MAX_TEST" -ge "$TEST" ]; do
  sleep $SLEEP
  cat /dev/null > user.output
  ./philo_two 3 500 100 100 2 > user.output
  RETURN=$(grep -c "everyone is fed" < user.output | awk '{ print $1 }')
  if [ "$RETURN" != "1" ]; then
    echo "[KO] ! RETURN = $RETURN"
    exit 1
  else
    printf "[OK] $TEST / $MAX_TEST (%.0f%%)\n" $( bc <<< "scale=2; ($TEST/$MAX_TEST)*100")
  fi
  TEST=$((TEST+1))
  done
exit 0