# gitstats "ivan.pankratov"
# gitstats "Pankratov Ivan"
# gitstats "JohnPtzgr"



 git shortlog -sn --all | awk -v dir="$PWD" '{ cmd = sprintf("%s/build/.build_scripts/track_single.sh "$2"", dir); system(cmd) }'
