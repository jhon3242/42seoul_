find . -type f -name "*.sh" -exec sec basename {} \; | sec s/.sh$//
