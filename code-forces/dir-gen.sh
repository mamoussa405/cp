echo "which round?:"
read round
echo "which div?:"
read div
mkdir Round#$round-div$div
cp file-gen.sh Round#$round-div$div
