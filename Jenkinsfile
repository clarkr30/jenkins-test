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
                sh 'uname -a'
                echo 'Building...'
                sh 'whoami'
                sh 'ls'
                sh 'echo "--- PATH ---"'
                sh 'echo $PATH'
                sh 'echo "--- Which make ---"'
                sh 'which make || echo "make not found by which"'
                sh 'echo "--- find make ---"'
                // This might take time if the image is large
                sh 'find / -name make || echo "make not found by find"'
                sh 'echo "--- Running make clean ---"'
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