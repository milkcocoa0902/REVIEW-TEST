= aa
VSCODE
VSCode
VS Code

docker run -t --rm -v $(pwd):/book vvakame/review:5.8 /bin/bash -ci "review-init /book/test && chmod -R 777 /book/test"
cd test
docker run -t --rm -v $(pwd):/book vvakame/review:5.8 /bin/bash -ci "cd /book && rake pdf"
docker run -t --rm -v $(pwd):/book node:23.3.0-alpine3.20 /bin/sh -ci "cd /book && npm install -D textlint-plugin-review textlint-rule-preset-ja-technical-writing textlint-rule-prh"
docker run -t --rm -v $(pwd):/book node:23.3.0-alpine3.20 /bin/sh -ci "cd /book && chmod -R 777 package.json package-lock.json node_modules"
docker run -t --rm -v $(pwd):/book node:23.3.0-alpine3.20 /bin/sh -ci "cd /book && npx textlint --init && chmod 777 .textlintrc.json"

mkdir prh

docker run -t --rm -v $(pwd):/book node:23.3.0-alpine3.20 /bin/sh -ci "cd /book && npx textlint **/*.re"

