while true; do
  sleep 1
  RETURN=$(./philo_three 5 0 200 200 | grep -c "died" | awk '{ print $1 }')
  echo "Trying..."
  if [ "$RETURN" != "1" ]; then
    echo "[KO] ! RETURN = $RETURN"
    exit 1
  else
    echo "[OK] RETURN = $RETURN"
  fi
  done
exit 0