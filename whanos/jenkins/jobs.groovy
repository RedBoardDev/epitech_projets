folder('/Whanos base images') {
  description('Folder for Whanos base images.')
  displayName('Whanos base images')
}

folder('/Projects') {
  description('Folder for Projects.')
  displayName('Projects')
}

freeStyleJob('/Whanos base images/whanos-befunge') {
    description('Build Whanos base image.')
    displayName('Whanos base image - Befunge')
    keepDependencies(false)
    steps {
        shell('docker build -t whanos-befunge -f /images/befunge/Dockerfile.base')
    }
}

freeStyleJob('/Whanos base images/whanos-c') {
    description('Build Whanos base image.')
    displayName('Whanos base image - C')
    keepDependencies(false)
    steps {
        shell('docker build -t whanos-c -f /images/c/Dockerfile.base')
    }
}

freeStyleJob('/Whanos base images/whanos-java') {
    description('Build Whanos base image.')
    displayName('Whanos base image - Java')
    keepDependencies(false)
    steps {
        shell('docker build -t whanos-java -f /images/java/Dockerfile.base')
    }
}

freeStyleJob('/Whanos base images/whanos-javascript') {
    description('Build Whanos base image.')
    displayName('Whanos base image - Javascript')
    keepDependencies(false)
    steps {
        shell('docker build -t whanos-javascript -f /images/javascript/Dockerfile.base')
    }
}

freeStyleJob('/Whanos base images/whanos-python') {
    description('Build Whanos base image.')
    displayName('Whanos base image - Python')
    keepDependencies(false)
    steps {
        shell('docker build -t whanos-python -f /images/python/Dockerfile.base')
    }
}
