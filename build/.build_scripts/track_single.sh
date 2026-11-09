author="$1"
echo "Author: $author"
echo "Commits: $(git rev-list HEAD --author="$author" --count)"
echo "Additions and Deletions: $(git log --author="$author" --pretty=tformat: --numstat | grep -v '^-' | awk '{ add+=$1; rem+=$2
} END { print "(+):", add, "(-):", rem, "(+/-):" , rem + add }' )"