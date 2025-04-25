pipeline{
    agent{
        docker{
            image 'node:18.17.1-alpine3.18'
        }
    }

    parameters{
         booleanParam(name: 'RELEASE', defaultValue: false, description: 'Set to true for a release build')
    }

    stages{
        stage('Build'){
            steps{
                echo 'Building...'
                sh 'ls'
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