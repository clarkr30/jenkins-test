pipeline{
    agent{
        docker{
            image 'node:18.17.1-alpine3.18'
            args '-u root'
        }
    }

    parameters{
         booleanParam(name: 'RELEASE', defaultValue: false, description: 'Set to true for a release build')
    }

    stages{
        stage('Build'){
            steps{
                echo 'Building...'

                echo 'Installing build tools...'
                // Install make (and gcc/g++ if needed for C/C++) using Alpine package manager
                sh 'apk update'
                sh 'apk add --no-cache make build-base git' // build-base includes gcc, g++, make etc. on Alpine

                echo 'Running Build...'

                // Your debugging steps (can be removed once it works)
                sh 'echo "--- Running as User ---"'
                sh 'whoami'
                sh 'echo "--- Specific PATH Check ---"'
                sh 'echo $PATH'
                sh 'echo "--- Check which via sh ---"'
                sh 'which make || echo "make not found by which (sh)"' // Should work now
                sh 'echo "--- Attempt execution via full path ---"'
                sh '/usr/bin/make --version || echo "/usr/bin/make --version FAILED"' // Should work now

                sh 'make clean'
                sh "RELEASE=${params.RELEASE} make all"
                echo "Linux Native build complete."
            }
        }
        stage('Test'){
            steps{
                echo 'Testing...'
                sh './app test test test waaaaaaa'
            }
        }
        stage('Deploy'){
            steps{
                echo 'Deploying...'
            }
        }
    }
}